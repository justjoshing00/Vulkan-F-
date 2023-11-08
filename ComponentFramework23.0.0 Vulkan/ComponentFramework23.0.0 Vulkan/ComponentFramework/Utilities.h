#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>

namespace VkUtilities
{
	//In Vulkan, there are a lot of structs being created in order to use in other structs, pass them to function calls, and do other things like that.
	//Thier presence in VulkanRenderers (relatively) higher level function calls makes those calls much harder to read, so I'm creating a bunch of helper functions so 
	//I can move them here. 

    VkDescriptorSetLayoutBinding CreateDescriptorBinding(uint32_t binding_, uint32_t descriptor_count_, VkDescriptorType descriptor_type_, VkShaderStageFlagBits stage_flags_)
    {
        VkDescriptorSetLayoutBinding result{};
        result.binding = binding_;
        result.descriptorCount = descriptor_count_;
        result.descriptorType = descriptor_type_;
        result.pImmutableSamplers = nullptr;
        result.stageFlags = stage_flags_;
        return result;
    }

    auto CreatePipeLineinfo(VkStructureType stype_, VkShaderStageFlagBits stage_, VkShaderModule module_, const char* pName_)
    {
        VkPipelineShaderStageCreateInfo result{};
        result.sType = stype_;
        result.stage = stage_;
        result.module = module_;
        result.pName = pName_;
        return result;
    }
}
